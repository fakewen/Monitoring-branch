function Condition_Selector_Short()
{
  Block.prototype.init.call(this);
  this.type='Condition_Selector_Short';
  
    
      
        this.addAction( new Action('input'));
      
      
    
  
    
      
        this.addAction( new Action('control'));
      
      
        this.addSignal( new Signal('control'));
      
    
  
    
      
      
        this.addSignal( new Signal('output1'));
      
    
  
    
      
      
        this.addSignal( new Signal('output2'));
      
    
  
}


Condition_Selector_Short.prototype = new Block();
Condition_Selector_Short.prototype.constructor = Condition_Selector_Short;
Block.register('Condition_Selector_Short', Condition_Selector_Short);