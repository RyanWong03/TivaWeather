import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  const [temperature, setTemperature] = useState(null);

  const getTemperature = () => {
    // simulate a fetch (replace this with real sensor/backend later)
    const fakeTemp = Math.floor(Math.random() * 10 + 20); // random between 20–30°C
    setTemperature(fakeTemp);
  };

  return (
    <div>
      <h1>Room Temp Viewer 🌡️</h1>
      <button onClick={getTemperature}>View Temperature</button>
      {temperature !== null && (
        <p>Current temperature: {temperature}°C</p>
      )}
    </div>
  );
}

export default App;
