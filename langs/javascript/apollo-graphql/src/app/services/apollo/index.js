import ApolloClient, {
  createNetworkInterface,
  addTypename
} from 'apollo-client'
import { appConfig } from '../../config'

// networkInterface:
const networkInterface = createNetworkInterface({ uri: appConfig.apollo.networkInterface })

// when need token based authentication:
networkInterface.use([{
  applyMiddleware(req, next) {
    if (!req.options.headers) {
      req.options.headers = {}  // Create the header object if needed.
    }
    // get the authentication token from local storage if it exists
    req.options.headers.authorization = `Bearer ${process.env.GITHUB_API_KEY}`
    next()
  }
}])


export const apolloClient = new ApolloClient({
  networkInterface,
  queryTransformer: addTypename
})
