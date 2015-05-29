function Ultrasound_Sensor()
{
  Block.prototype.init.call(this);
  this.type='Ultrasound_Sensor';
  
    
      
      
        this.addSignal( new Signal('signal'));
      
    
  
    
      
        this.addAction( new Action('refresh_rate'));
      
      
        this.addSignal( new Signal('refresh_rate'));
      
    
  
}


Ultrasound_Sensor.prototype = new Block();
Ultrasound_Sensor.prototype.constructor = Ultrasound_Sensor;
Block.register('Ultrasound_Sensor', Ultrasound_Sensor);