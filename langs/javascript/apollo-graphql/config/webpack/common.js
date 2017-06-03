const webpack       = require('webpack');
const path          = require('path');
const autoprefixer  = require('autoprefixer');
const precss        = require('precss');

module.exports = {
  output: {
    path: path.resolve('./dist/'),
    filename: 'bundle.js',
  },
  module: {
    rules: [{
      test: /\.jsx?$/,
      loaders: ['babel-loader'],
      exclude: /node_modules/,
    },  {
      test: /\.scss$/,
      use: [
        "style-loader", "css-loader", "postcss-loader", "sass-loader"
      ]
    }, {
      test: /\.css$/,
      use: [
        "style-loader", "css-loader", "postcss-loader"
      ]
    }, {
      test: /\.(eot|woff|woff2|ttf|svg|png|jpe?g|gif)(\?\S*)?$/,
      loader: 'url?limit=100000@name=[name][ext]'
    }]
  },
  plugins: [
    new webpack.LoaderOptionsPlugin({
      options: {
        postcss: [ precss, autoprefixer ]
      }
    }),
    new webpack.NamedModulesPlugin(),
    new webpack.ProvidePlugin({
      $: 'jquery',
      jQuery: 'jquery'
    }),
    new webpack.DefinePlugin({
      'process.env': {
        'NODE_ENV': JSON.stringify('dev'),
        'GITHUB_API_KEY': JSON.stringify(process.env.GITHUB_API_KEY),
      }
    })
  ]
};
