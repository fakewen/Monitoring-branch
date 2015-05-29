function If_Boolean()
{
  Block.prototype.init.call(this);
  this.type='If_Boolean';
  
    
      
        this.addAction( new Action('condition'));
      
      
    
  
    
      
        this.addAction( new Action('if_true'));
      
      
    
  
    
      
        this.addAction( new Action('if_false'));
      
      
    
  
    
      
      
        this.addSignal( new Signal('output'));
      
    
  
}


If_Boolean.prototype = new Block();
If_Boolean.prototype.constructor = If_Boolean;
Block.register('If_Boolean', If_Boolean);