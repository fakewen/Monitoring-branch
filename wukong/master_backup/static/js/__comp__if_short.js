function If_Short()
{
  Block.prototype.init.call(this);
  this.type='If_Short';
  
    
      
        this.addAction( new Action('condition'));
      
      
    
  
    
      
        this.addAction( new Action('if_true'));
      
      
    
  
    
      
        this.addAction( new Action('if_false'));
      
      
    
  
    
      
      
        this.addSignal( new Signal('output'));
      
    
  
}


If_Short.prototype = new Block();
If_Short.prototype.constructor = If_Short;
Block.register('If_Short', If_Short);