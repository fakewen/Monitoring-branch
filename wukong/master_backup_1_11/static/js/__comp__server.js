function Server()
{
  Block.prototype.init.call(this);
  this.type='Server';
  
    
      
        this.addAction( new Action('input'));
      
      
        this.addSignal( new Signal('input'));
      
    
  
}


Server.prototype = new Block();
Server.prototype.constructor = Server;
Block.register('Server', Server);