const createRand = () => Math.ceil(Math.random() * 10)

const initialState = {
  current: createRand(),
  elevator: createRand(),
}

export default (state = initialState, { type }) => {
  switch(type) {
    case 'upper':
      return { ...state, ...{ elevator: state.elevator + 1 }}
    case 'downer':
      return { ...state, ...{ elevator: state.elevator - 1 }}
    default:
      return state
  }
}
