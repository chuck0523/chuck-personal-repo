const webpack = require('webpack');

module.exports = {
  entry: [
    './src/app/index.js'
  ],
  plugins: [
    new webpack.optimize.UglifyJsPlugin()
  ]
};
