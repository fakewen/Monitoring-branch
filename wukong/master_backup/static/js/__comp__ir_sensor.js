function IR_Sensor()
{
  Block.prototype.init.call(this);
  this.type='IR_Sensor';
  
    
      
      
        this.addSignal( new Signal('signal'));
      
    
  
    
      
        this.addAction( new Action('refresh_rate'));
      
      
        this.addSignal( new Signal('refresh_rate'));
      
    
  
}


IR_Sensor.prototype = new Block();
IR_Sensor.prototype.constructor = IR_Sensor;
Block.register('IR_Sensor', IR_Sensor);