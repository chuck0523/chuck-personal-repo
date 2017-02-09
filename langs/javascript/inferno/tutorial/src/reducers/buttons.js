const initialState = {
  up: false,
  down: false,
  isPushed: false,
}

export default (state = initialState, { type }) => {
  switch(type) {
    case 'toggleUp':
      return { ...state, ...{ up: !state.up }, ...{ isPushed: true } }
    case 'toggleDown':
      return { ...state, ...{ down: !state.down }, ...{ isPushed: true } }
    case 'stop':
      return { ...state, ...{ up: false }, ...{ down: false } }
    default:
      return state
  }
}