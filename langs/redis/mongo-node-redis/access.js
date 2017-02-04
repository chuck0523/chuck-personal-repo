module.exports.saveBook = (db, title, author, text, callback) => {
  db.collection('text').save({
    title: title,
    author: author,
    text: text
  }, callback)
}

module.exports.findBookByTitle = (db, title, callback) => {
  db.collection('text').findOne({ title }, (err, doc) => {
    callback((err || !doc) ? null : doc.text)
  })
}

module.exports.findBookByTitleCached = (db, redis, title, callback) => {
  redis.get(title, (err, reply) => {
    if (err) {
      callback(null)
    } else if (reply) {
      console.log('found in redis')
      // キャッシュにて書籍を発見
      callback(JSON.parse(reply))
    } else {
      console.log('not found in redis, found in mongo')

      // キャッシュに書籍が無かったのでDBにクエリ発行
      db.collection('text').findOne({ title }, (err, doc) => {
        if (err || !doc) {
          // DBにも書籍が無かった場合
          callback(null)
        } else {
          // DBにて書籍を発見
          // キャッシュにセーブして、クライアントにリターンする
          redis.set(title, JSON.stringify(doc), () => {
            callback(doc)
          })
        }
      })
    }
  })
}
