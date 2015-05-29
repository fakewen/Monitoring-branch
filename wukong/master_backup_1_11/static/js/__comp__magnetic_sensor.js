function Magnetic_Sensor()
{
  Block.prototype.init.call(this);
  this.type='Magnetic_Sensor';
  
    
      
      
        this.addSignal( new Signal('output'));
      
    
  
    
      
        this.addAction( new Action('refresh_rate'));
      
      
        this.addSignal( new Signal('refresh_rate'));
      
    
  
    
      
      
        this.addSignal( new Signal('__pin'));
      
    
  
}


Magnetic_Sensor.prototype = new Block();
Magnetic_Sensor.prototype.constructor = Magnetic_Sensor;
Block.register('Magnetic_Sensor', Magnetic_Sensor);