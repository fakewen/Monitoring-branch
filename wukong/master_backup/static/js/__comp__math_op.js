function Math_Op()
{
  Block.prototype.init.call(this);
  this.type='Math_Op';
  
    
      
        this.addAction( new Action('input1'));
      
      
    
  
    
      
        this.addAction( new Action('input2'));
      
      
    
  
    
      
        this.addAction( new Action('operator'));
      
      
        this.addSignal( new Signal('operator'));
      
    
  
    
      
      
        this.addSignal( new Signal('output'));
      
    
  
    
      
      
        this.addSignal( new Signal('remainder'));
      
    
  
}


Math_Op.prototype = new Block();
Math_Op.prototype.constructor = Math_Op;
Block.register('Math_Op', Math_Op);