import React from 'react'
import { connect }            from 'react-redux';
import { bindActionCreators } from 'redux';
import * as viewsActions      from '../redux/modules/views';
import { App } from '../components'
import gql                    from 'graphql-tag';
import { graphql }            from 'react-apollo';


/* -----------------------------------------
  GraphQL - Apollo client
 ------------------------------------------*/

const FoundRepository = gql`
 query Search ($q: String!) {
   search(query: $q, first: 10, type: REPOSITORY) {
     edges {
       node {
         ... on Repository {
           id,
           name,
           url
         }
       }
     }
   }
}
`

// 1- add queries:
const AppWithQuery = graphql(
  FoundRepository,
  {
    options: {
      // variables: (ownProps) => ({variables: {user: 'VXNlcjox'}})
      variables: {
        q: 'chuck0523'
      }
    },
    name: 'findRepository',
    props: ({
      ownProps,
      findRepository:
      {
        search,
      }
    }) => {
      // // TODO: find a better solution to dispatch redux action on query result to set 'state.userAuth.isAuthenticated'
      // setTimeout(
      //   () => ownProps.checkUserAuth(), 0
      // );
      return {
        repo: {...search},
      };
    }

  }
)(App)


/* -----------------------------------------
  Redux
 ------------------------------------------*/

const mapStateToProps = (state) => {
  return {
    // view store:
    currentView:  state.views.currentView
  };
};

const mapDispatchToProps = (dispatch) => {
  return bindActionCreators(
    {
      // views actions
      enterHome: viewsActions.enterHome,
      leaveHome: viewsActions.leaveHome
    },
    dispatch
  );
};

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(AppWithQuery);
