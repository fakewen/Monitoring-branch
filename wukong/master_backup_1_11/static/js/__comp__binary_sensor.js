function Binary_Sensor()
{
  Block.prototype.init.call(this);
  this.type='Binary_Sensor';
  
    
      
        this.addAction( new Action('current_value'));
      
      
        this.addSignal( new Signal('current_value'));
      
    
  
    
      
        this.addAction( new Action('refresh_rate'));
      
      
        this.addSignal( new Signal('refresh_rate'));
      
    
  
}


Binary_Sensor.prototype = new Block();
Binary_Sensor.prototype.constructor = Binary_Sensor;
Block.register('Binary_Sensor', Binary_Sensor);