var object_ip = function(){
    return new Promise( function( resolve, reject ){
        let Ips = {};
        let counter = 1;
        let os=require('os');
        let ifaces=os.networkInterfaces();
        for( let i = 0; i < Object.keys(ifaces).length; i++){
            ifaces[Object.keys(ifaces)[i]].forEach(el=>{
                if(!!el.address){
                    Ips['Ipv'+counter.toString()] = el.address;
                    counter++;
                }
            })
        }

        if(!!Object.keys(Ips).length){
            resolve(Ips);
        }else{
            reject("Dont Have IP");
        }
    })
}

object_ip()

    .then( function(result){ 
        console.log(result); 
    })
    .catch( function(error){ 
        console.error(error);
    })