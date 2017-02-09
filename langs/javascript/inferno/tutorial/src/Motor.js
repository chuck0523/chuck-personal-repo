import Inferno from 'inferno'

const Motor = ({ floors, buttons, actions }) => {
  const isButtonOff = !buttons.up && !buttons.down
  setTimeout(() => {
    // elevator not called
    if(isButtonOff) {
      return
    }
    // open
    if(floors.elevator === floors.current) {
      actions.stop()
    }
    // elevator go down
    if(floors.elevator > floors.current) {
      actions.moveDowner()
    }
    // elevator go up
    if(floors.elevator < floors.current) {
      actions.moveUpper()
    }
  }, 1000)
  return (
    <div></div>
  )
}

export default Motor