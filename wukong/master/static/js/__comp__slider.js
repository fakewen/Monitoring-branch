function Slider()
{
  Block.prototype.init.call(this);
  this.type='Slider';
  
    
      
        this.addAction( new Action('low_value'));
      
      
        this.addSignal( new Signal('low_value'));
      
    
  
    
      
        this.addAction( new Action('high_value'));
      
      
        this.addSignal( new Signal('high_value'));
      
    
  
    
      
        this.addAction( new Action('output'));
      
      
        this.addSignal( new Signal('output'));
      
    
  
    
      
        this.addAction( new Action('refresh_rate'));
      
      
        this.addSignal( new Signal('refresh_rate'));
      
    
  
}


Slider.prototype = new Block();
Slider.prototype.constructor = Slider;
Block.register('Slider', Slider);