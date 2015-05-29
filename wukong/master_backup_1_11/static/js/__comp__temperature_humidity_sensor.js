function Temperature_Humidity_Sensor()
{
  Block.prototype.init.call(this);
  this.type='Temperature_Humidity_Sensor';
  
    
      
      
        this.addSignal( new Signal('current_value_temperature'));
      
    
  
    
      
      
        this.addSignal( new Signal('current_value_humidity'));
      
    
  
    
      
        this.addAction( new Action('refresh_rate'));
      
      
        this.addSignal( new Signal('refresh_rate'));
      
    
  
}


Temperature_Humidity_Sensor.prototype = new Block();
Temperature_Humidity_Sensor.prototype.constructor = Temperature_Humidity_Sensor;
Block.register('Temperature_Humidity_Sensor', Temperature_Humidity_Sensor);