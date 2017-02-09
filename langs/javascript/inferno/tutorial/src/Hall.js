import Inferno from 'inferno';
import { bindActionCreators } from 'redux';
import { connect } from 'inferno-redux'
import Elevators from './Elevators'
import * as buttonsActions from './actions/buttons'
import * as moveActions from './actions/move'
import Motor from './Motor'

const Hall = (state) => {
  return (
    <div>
      <header>{ state.floors.current } F</header>
      <Elevators { ...state } />
      <Motor { ...state } />
    </div>
  )
}

const mapStateToProps = ({ buttons, floors }) => {
  return { buttons, floors }
}

const mapDispatchToProps = (dispatch) => {
  return { actions: bindActionCreators({ ...moveActions, ...buttonsActions }, dispatch) }
}

export default connect(mapStateToProps, mapDispatchToProps)(Hall)
