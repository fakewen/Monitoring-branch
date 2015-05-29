function Condition_Selector_Boolean()
{
  Block.prototype.init.call(this);
  this.type='Condition_Selector_Boolean';
  
    
      
        this.addAction( new Action('input'));
      
      
    
  
    
      
        this.addAction( new Action('control'));
      
      
        this.addSignal( new Signal('control'));
      
    
  
    
      
      
        this.addSignal( new Signal('output1'));
      
    
  
    
      
      
        this.addSignal( new Signal('output2'));
      
    
  
}


Condition_Selector_Boolean.prototype = new Block();
Condition_Selector_Boolean.prototype.constructor = Condition_Selector_Boolean;
Block.register('Condition_Selector_Boolean', Condition_Selector_Boolean);