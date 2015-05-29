function Pressure_Sensor_0()
{
  Block.prototype.init.call(this);
  this.type='Pressure_Sensor_0';
  
    
      
        this.addAction( new Action('refresh_rate'));
      
      
        this.addSignal( new Signal('refresh_rate'));
      
    
  
    
      
        this.addAction( new Action('output'));
      
      
        this.addSignal( new Signal('output'));
      
    
  
    
      
        this.addAction( new Action('high'));
      
      
        this.addSignal( new Signal('high'));
      
    
  
    
      
        this.addAction( new Action('low'));
      
      
        this.addSignal( new Signal('low'));
      
    
  
}


Pressure_Sensor_0.prototype = new Block();
Pressure_Sensor_0.prototype.constructor = Pressure_Sensor_0;
Block.register('Pressure_Sensor_0', Pressure_Sensor_0);