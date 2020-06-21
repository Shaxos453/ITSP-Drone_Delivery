var ros = new ROSLIB.Ros({
        url : 'ws://localhost:9090'
    });
    ros.on('connection', function() {
        console.log('Connected to websocket server.');
    });

    ros.on('error', function(error) {
        console.log('Error connecting to websocket server: ', error);
    });

    ros.on('close', function() {
        console.log('Connection to websocket server closed.');
    });

    //fetching droneID
    const delID = document.getElementById("delID");
    var ID = delID.innerText;
    let droneID = ID.slice(-1);

document.getElementById("Delivered").disabled = true;

    var lat, long, reached;

    //subscription
    if (droneID == '1'){
      var getloc = new ROSLIB.Topic({
        ros : ros,
        name : '/uav0/mavros/global_position/global',
        messageType : 'sensor_msgs/NavSatFix'        
      });
    }
    else if (droneID == '2'){
      var getloc = new ROSLIB.Topic({
        ros : ros,
        name : '/uav1/mavros/global_position/global',
        messageType : 'sensor_msgs/NavSatFix'
      });
    }
    else if (droneID == '3'){
      var getloc = new ROSLIB.Topic({
        ros : ros,
        name : '/uav2/mavros/global_position/global',
        messageType : 'sensor_msgs/NavSatFix'
      });
    }

    getloc.subscribe(function(message) {
      lat = message.latitude;
      long = message.longitude;

    });

    //subscription for delivered button
    if (droneID == '1'){
      var done = new ROSLIB.Topic({
        ros : ros,
        name : '/uav0/mavros/mission/reached',
        messageType : 'mavros_msgs/WaypointReached'
      });
    }
    else if (droneID == '2'){
      var done = new ROSLIB.Topic({
        ros : ros,
        name : '/uav1/mavros/mission/reached',
        messageType : 'mavros_msgs/WaypointReached'
      });
    }
    else if (droneID == '3'){
      var done = new ROSLIB.Topic({
        ros : ros,
        name : '/uav2/mavros/mission/reached',
        messageType : 'mavros_msgs/WaypointReached'
      });
    }

    done.subscribe(function(message) {
      reached = message.wp_seq;
    });

// adding delivery button activation and flash message
if(reached==2){
    document.getElementById("flash").innerHTML="Your Delivery has reached its destination. Press Delivered button after collecting it."
    document.getElementById("Delivered").disabled = false;
}

var map, watchId, userPin;

function GetMap()
{
    map = new Microsoft.Maps.Map('#myMap', {
        credentials:'Auy26xShWKNnx2Ko3hic0uOAMBpK0jy_TtfM06-nuGi3WBeUREIlgzJMLqylaDs8'
    });
}
/*
function StartTracking() {
    //Add a pushpin to show the user's location.
    userPin = new Microsoft.Maps.Pushpin(map.getCenter(), { visible: false });
    map.entities.push(userPin);
    watchId = navigator.geolocation.watchPosition(UsersLocationUpdated);
    console.log('started Tracking');
    console.log('Push '+lat + ' ' +long);
}

function UsersLocationUpdated() {
    var loc = new Microsoft.Maps.Location(lat, long);

    //Update the user pushpin.
    userPin.setLocation(loc);
    userPin.setOptions({ visible: true });
    console.log('Updated '+lat + ' ' +long);

    //Center the map on the user's location.
    map.setView({ center: loc });
}
*/

var tid;

function startPush(){
  putPin();
  tid = setTimeout(pushLoc, 2000);
}

function pushLoc(){
  var loc = new Microsoft.Maps.Location(lat, long);

  //Update the user pushpin.
  userPin.setLocation(loc);
  userPin.setOptions({ visible: true });
  console.log('Updated '+lat + ' ' +long);

  //Center the map on the user's location.
  map.setView({ center: loc });

  tid = setTimeout(pushLoc, 5000);
}

function putPin(){
  userPin = new Microsoft.Maps.Pushpin(map.getCenter(), { visible: false });
    map.entities.push(userPin);
}

function StopTracking() {
    getloc.unsubscribe();
    clearTimeout(tid);
    //Remove the user pushpin.
    map.entities.clear();
}

var deliver = document.getElementById("Delivered")

var onDelivery = function(){
    //service def
    var web_inputClient = new ROSLIB.Service({
        ros : ros,
        name : '/Delivery',
        serviceType : 'offb/Delivery'  //instead of webinput add .srv file name which will be in offb/src
     });
    var request = new ROSLIB.ServiceRequest({
        delivered : true,
        DroneID : droneID
    });
    //calling service check res.success
    console.log('service');
    web_inputClient.callService(request, function(res) {
        console.log('Result for service call on '+ web_inputClient.name + ': '+ res.success);
    });
}


deliver.addEventListener("submit",  onDelivery);
