mydb=db.getSiblingDB("wukong")

var mapFunction = function() {
					if(this.timestamp!=null){
                      var ts = this.timestamp;
                      ts.setMilliseconds(0);
                      ts.setSeconds(0);
                      ts.setMinutes(0);
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
                     { 
                      query: { timestamp: { $gt: ISODate("2015-03-03T15:05:32.203Z") } },
                      out: {reduce:"readingsbyhour"} }
                   )                               

