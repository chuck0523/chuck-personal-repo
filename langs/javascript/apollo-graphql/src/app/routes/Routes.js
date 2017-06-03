import React from 'react'
import {
 Router,
 Route,
 browserHistory
} from 'react-router'
import { createBrowserHistory } from 'history'
import { ApolloProvider } from 'react-apollo'
import { syncHistoryWithStore } from 'react-router-redux'
import { App } from '../containers'
import DevTools from '../redux/dev-tools/DevTools'
import configureStore, {
  client
} from '../redux/store/configure';

const store         = configureStore()
const syncedHistory = syncHistoryWithStore(createBrowserHistory(), store)

export const Routes = () => {
  return (
    <ApolloProvider store={store} client={client}>
      <div>
        <Router history={syncedHistory}>
          <Route path="/" component={App} >
            {/* non protected views */}


            <Route path="*" component={() => (<div>Not Found</div>)} />
          </Route>
        </Router>
        { process.env.NODE_ENV !== 'production' ? <DevTools /> : null }
      </div>
    </ApolloProvider>
  )
}
