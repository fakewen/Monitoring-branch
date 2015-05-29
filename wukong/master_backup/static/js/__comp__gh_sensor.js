function Gh_Sensor()
{
  Block.prototype.init.call(this);
  this.type='Gh_Sensor';
  
    
      
        this.addAction( new Action('enable'));
      
      
        this.addSignal( new Signal('enable'));
      
    
  
    
      
        this.addAction( new Action('refresh_rate'));
      
      
        this.addSignal( new Signal('refresh_rate'));
      
    
  
}


Gh_Sensor.prototype = new Block();
Gh_Sensor.prototype.constructor = Gh_Sensor;
Block.register('Gh_Sensor', Gh_Sensor);