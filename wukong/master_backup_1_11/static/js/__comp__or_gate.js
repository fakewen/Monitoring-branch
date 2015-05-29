function Or_Gate()
{
  Block.prototype.init.call(this);
  this.type='Or_Gate';
  
    
      
        this.addAction( new Action('input1'));
      
      
    
  
    
      
        this.addAction( new Action('input2'));
      
      
    
  
    
      
      
        this.addSignal( new Signal('output'));
      
    
  
}


Or_Gate.prototype = new Block();
Or_Gate.prototype.constructor = Or_Gate;
Block.register('Or_Gate', Or_Gate);