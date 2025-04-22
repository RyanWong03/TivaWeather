import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  const [temperature, setTemperature] = useState(null);

  const fetchTemperature = () => {
    fetch('http://127.0.0.1:5000/api/temperature')
      .then((response) => response.json())
      .then((data) => setTemperature(data.temperature))
      .catch((error) => console.error('Error fetching temperature:', error));
  };

  return (
    <div>
      <h1>Room Temp Viewer 🌡️</h1>
      <button onClick={fetchTemperature}>View Temperature</button>
      {temperature !== null && (
        <p>Current temperature: {temperature}°C</p>
      )}
      
      <br></br>
      <br></br>
      
      <button>Turn on Fan</button>
    </div>
  );
}

export default App;
