function Not_Gate()
{
  Block.prototype.init.call(this);
  this.type='Not_Gate';
  
    
      
        this.addAction( new Action('input'));
      
      
    
  
    
      
      
        this.addSignal( new Signal('output'));
      
    
  
}


Not_Gate.prototype = new Block();
Not_Gate.prototype.constructor = Not_Gate;
Block.register('Not_Gate', Not_Gate);