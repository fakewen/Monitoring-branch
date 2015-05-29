mydb=db.getSiblingDB("wukong")

var mapFunction = function() {
					if(this.timestamp!=null){
                      var ts = this.timestamp;
                      ts.setMilliseconds(0);
                      ts.setSeconds(0);
                      ts.setMinutes(Math.floor(this.timestamp.getMinutes()/15)*15 );
                      var value = this.value;

                      emit( {	node_id: this.node_id,
                      			port: this.port,
                      			timestamp: ts
                      		},
                      		value );
                  	}
                  };
var reduceFunction = function(key, values) {
                          return Array.avg(values);
                      };         

mydb.readings.mapReduce(
                     mapFunction,
                     reduceFunction,
                     { out: "readingsby15min" }
                   )                               

