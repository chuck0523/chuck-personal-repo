import Inferno from 'inferno';
import Elevator from './Elevator'
import Buttons from './Buttons'

const style = {
  display: 'flex'
}

const Elevators = ({ floors, buttons, actions }) => {
  return (
    <main style={ style }>
      <Elevator floors={ floors } isPushed={ buttons.isPushed } />
      <Buttons buttons={ buttons } actions={ actions } />
    </main>
  )
}

export default Elevators