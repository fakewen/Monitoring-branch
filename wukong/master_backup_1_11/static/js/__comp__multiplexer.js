function Multiplexer()
{
  Block.prototype.init.call(this);
  this.type='Multiplexer';
  
    
      
        this.addAction( new Action('selector'));
      
      
        this.addSignal( new Signal('selector'));
      
    
  
    
      
        this.addAction( new Action('input1'));
      
      
        this.addSignal( new Signal('input1'));
      
    
  
    
      
        this.addAction( new Action('input2'));
      
      
        this.addSignal( new Signal('input2'));
      
    
  
    
  
    
  
    
      
        this.addAction( new Action('id'));
      
      
        this.addSignal( new Signal('id'));
      
    
  
    
      
        this.addAction( new Action('output'));
      
      
        this.addSignal( new Signal('output'));
      
    
  
}


Multiplexer.prototype = new Block();
Multiplexer.prototype.constructor = Multiplexer;
Block.register('Multiplexer', Multiplexer);