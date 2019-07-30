import React from 'react';
import logo from './logo.svg';
import './App.css';

class App extends React.Component {
  async componentDidMount() {
    if (window.dataLayer) {
      await window.dataLayer.push({ event: "optimize.activate" });
    }
    this.intervalId = setInterval(() => {
      if (window.google_optimize !== undefined) {
        const variant = window.google_optimize.get("9_shIJY1QZasjcOqsBac0A");
        console.log(variant);
        this.setState({ variant });
        clearInterval(this.intervalId);
      }
    }, 200);
  }
    render() {
      return (
        <div className="App">
          <header className="App-header">
            <img src={logo} className="App-logo" alt="logo" />
            <p>
              Edit <code>src/App.js</code> and save to reload.
            </p>
            <a
              className="App-link"
              href="https://reactjs.org"
              target="_blank"
              rel="noopener noreferrer"
            >
              Learn React
            </a>
          </header>
        </div>
      );
    }
}

export default App;
