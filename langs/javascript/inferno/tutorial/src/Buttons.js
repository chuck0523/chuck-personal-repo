import Inferno from 'inferno'

const Buttons = ({ buttons, actions }) => {
  const onUpButton = () => {
    actions.toggleUp()
    actions.pushButton()
  }
  const onDownButton = () => {
    actions.toggleDown()
    actions.pushButton()
  }
  const buttonStyle = {
    display: 'block'
  }
  return (
    <div>
      <button style={buttonStyle} onClick={ onUpButton }>
        { (buttons.up) ? '▲' : '△' }
      </button>
      <button style={buttonStyle} onClick={ onDownButton }>
        { (buttons.down) ? '▼' : '▽' }
      </button>
    </div>
  )
}

export default Buttons