function Xor_Gate()
{
  Block.prototype.init.call(this);
  this.type='Xor_Gate';
  
    
      
        this.addAction( new Action('input1'));
      
      
    
  
    
      
        this.addAction( new Action('input2'));
      
      
    
  
    
      
      
        this.addSignal( new Signal('output'));
      
    
  
}


Xor_Gate.prototype = new Block();
Xor_Gate.prototype.constructor = Xor_Gate;
Block.register('Xor_Gate', Xor_Gate);