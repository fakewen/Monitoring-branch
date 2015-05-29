function LED()
{
  Block.prototype.init.call(this);
  this.type='LED';
  
    
      
        this.addAction( new Action('refresh_rate'));
      
      
        this.addSignal( new Signal('refresh_rate'));
      
    
  
    
      
        this.addAction( new Action('port1'));
      
      
        this.addSignal( new Signal('port1'));
      
    
  
    
      
        this.addAction( new Action('port2'));
      
      
        this.addSignal( new Signal('port2'));
      
    
  
    
      
        this.addAction( new Action('port3'));
      
      
        this.addSignal( new Signal('port3'));
      
    
  
    
      
        this.addAction( new Action('port4'));
      
      
        this.addSignal( new Signal('port4'));
      
    
  
}


LED.prototype = new Block();
LED.prototype.constructor = LED;
Block.register('LED', LED);