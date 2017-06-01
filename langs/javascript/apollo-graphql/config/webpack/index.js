const merge = require('webpack-merge')
const isDev = process.env.NODE_ENV === 'dev'
const commonConfig = require('./common')
const envConfig = isDev ? require('./dev') : require('./prod')

module.exports = merge(commonConfig, envConfig)
