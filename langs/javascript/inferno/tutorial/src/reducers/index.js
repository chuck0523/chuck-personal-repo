import { combineReducers } from 'redux'
import floorsReducer from './floors'
import buttonsReducer from './buttons'

export default combineReducers({
  floors: floorsReducer,
  buttons: buttonsReducer,
})