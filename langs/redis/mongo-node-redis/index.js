const express = require('express')
const MongoClient = require('mongodb').MongoClient
const app = express()
const bodyParser = require('body-parser')
const mongoUrl = 'mongodb://localhost:27017/textmonkey'

app.use(bodyParser.urlencoded({ extended: false }))
app.use(bodyParser.json())

const redisClient = require('redis').createClient
const redis = redisClient(6379, 'localhost')

const access = require('./access.js')

MongoClient.connect(mongoUrl, (err, db) => {
  if(err) {
    throw 'Error connecting to database - ' + err
  }
  app.post('/book', (req, res) => {
    if (!req.body.title || !req.body.author) {
      res.status(400).send("Please send a title and an author for the book")
    } else if (!req.body.text) {
      res.status(400).send("Please send some text for the book")
    } else {
      access.saveBook(db, req.body.title, req.body.author, req.body.text, (err) => {
        if (err) {
          res.status(500).send("Server error")
        } else {
          res.status(201).send("Saved")
        }
      })
    }
  })
  app.get('/book/:title', (req, res) => {
    if (!req.params['title']) {
      res.status(400).send("Please send a proper title")
    } else {
      access.findBookByTitleCached(db, redis, req.params['title'], (text) => {
        if (!text) {
          res.status(500).send("Server error")
        } else {
          res.status(200).send(text)
        }
      })
    }
  })
  app.listen(8000, () => {
    console.log('Listening on port 8000')
  })
})
