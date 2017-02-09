import Inferno from 'inferno';

const boxStyle = {
  border: '1px solid #333',
}

const OpenedElevator = () => {
  return (
    <div>Open!</div>
  )
}
const ClosedElevator = () => {
  return (
    <div>Closed</div>
  )
}

const Elevator = ({ floors, isPushed }) => {
  const elevatorArrived = ( floors.current === floors.elevator )
  return (
    <div>
      <div>{ floors.elevator } F</div>
      <div style={ boxStyle }>
        { ( elevatorArrived && isPushed ) ? <OpenedElevator /> : <ClosedElevator /> }
      </div>
    </div>
  )
}

export default Elevator