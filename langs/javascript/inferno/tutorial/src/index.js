import Inferno from 'inferno';
import { Provider } from 'inferno-redux'
import { createStore } from 'redux'
import reducers from './reducers'
import Hall from './Hall'

const store = createStore(reducers)

Inferno.render(
  <Provider store={ store }>
    <Hall />
  </Provider>
  , document.getElementById('app'));
