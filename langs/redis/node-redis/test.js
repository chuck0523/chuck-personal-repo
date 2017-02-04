// Using Redis with Node.js: https://www.sitepoint.com/using-redis-node-js/

const redis = require('redis')
const client = redis.createClient()
// As default 127.0.0.1:6379 will be used.
// const client = redis.createClient(port, host)


client.on('connect', () => {
  console.log('connected!')
})

client.set('framework', 'AngularJS')
// Or client.set(['framework', 'AngularJS'])

// with reply
client.set('framework', 'AngularJS', (err, reply) => {
  console.log(reply)
})

client.get('framework', function(err, reply) {
  console.log(reply) // AngularJS
})

// hash
client.hmset('frameworks', 'javascript', 'AngularJS', 'css', 'Bootstrap', 'node', 'Express')
client.hgetall('frameworks', (err, object) => {
  console.log(object) // { javascript: 'AngularJS', css: 'Bootstrap', node: 'Express' }
})

// list
client.rpush(['scores', 10, 20, 30], (err, reply) => {
  console.log(reply)
})
client.lrange('scores', 0, 2, (err, reply) => {
  console.log(reply)
})

// set
client.sadd(['tags', 'angularjs', 'backbonejs', 'emberjs'], (err, reply) => {
  console.log(reply) // 3
})
client.smembers('tags', function(err, reply) {
    console.log(reply)
})

// key manipulate
client.exists('key', (err, reply) => {
  if (reply === 1) {
    console.log('exists')
  } else {
    console.log('doesn\'t exist') // here
  }
})

// del
client.del('frameworks', (err, reply) => {
  console.log(reply)
})

// expire
client.set('key1', 'val1')
client.expire('key1', 30)

client.set('key2', 10, () => {
  client.incr('key2', (err, reply) => {
    console.log(reply) // 11
  })
})
