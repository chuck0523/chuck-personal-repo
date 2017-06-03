import React from 'react'
import ReactDOM from 'react-dom'
import injectTpEventPlugin  from 'react-tap-event-plugin'
import { Routes } from './routes/Routes'

import { AppContainer } from 'react-hot-loader'
// AppContainer is a necessary wrapper component for HMR

const render = (Component) => {
  ReactDOM.render(
    <AppContainer>
      <Component/>
    </AppContainer>,
    document.getElementById('root')
  )
}

injectTpEventPlugin()

render(Routes)

// Hot Module Replacement API
if(module.hot) {
  module.hot.accept('./components/App', () => {
    render(Routes)
  })
}
