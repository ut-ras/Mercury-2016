#!/usr/bin/python
from bottle import route, request, run, get
# import serial
# import time
# from bottle import route, run, template
# import io
# import sys
# import picamera

# camera = picamera.PiCamera()
# ser = serial.Serial('/dev/ttyUSB0',9600)


@route('/control')
def contro():
    return '''
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="http://code.jquery.com/mobile/1.4.2/jquery.mobile-1.4.2.min.css">
<script src="http://code.jquery.com/jquery-1.10.2.min.js"></script>
<script src="http://code.jquery.com/mobile/1.4.2/jquery.mobile-1.4.2.min.js"></script>
<script>
$(document).ready(function() {
  $("#ckLED").change(function() {
    var isChecked = $("#ckLED").is(":checked") ? 1:0; 
    $.ajax({
            url: '/action',
            type: 'POST',
            data: { strID:'ckLED', strState:isChecked }
    });
    console.log( "The switch was flipped" );
    });

    
     $(window).keyup(function(event){
    var keyCode = event.keyCode;
    if (keyCode == 87)
    {
        $("#wbutton").button({
               disabled:false
            }); 
    }
    });
  
    $(window).keydown(function(event){
    var keyCode = event.keyCode;
    document.getElementById("throughput").value = keyCode;
    if (keyCode == 73)
    {
    var leftspeed = parseInt(document.getElementById("leftspeed").value);
    if (leftspeed < 9)
    {
        document.getElementById("leftspeed").value = leftspeed + 1;
    }
    }
    
    if (keyCode ==75)
    {
    var leftspeed = parseInt(document.getElementById("leftspeed").value);
    if (leftspeed > 0)
    {
        document.getElementById("leftspeed").value = leftspeed - 1;
    }
    }
    
    if (keyCode == 76)
    {
    var rightspeed = parseInt(document.getElementById("rightspeed").value);
    if (rightspeed < 9)
    {
        document.getElementById("rightspeed").value = rightspeed + 1;
    }
    }
    
    if (keyCode == 74)
    {
    var rightspeed = parseInt(document.getElementById("rightspeed").value);
    if (rightspeed > 0)
    {
        document.getElementById("rightspeed").value = rightspeed - 1;
    }
    }
    
    if (keyCode == 87)
    {
        $("#wbutton").button({
               disabled:true
            }); 
    }
    //alert(event.keyCode);
    $.ajax({
                url: '/action',
                type: 'POST',
                data: {keyPressed:keyCode }
        });
    });
 
});
</script>
</head>
<body>
<div data-role="page">
  <div data-role="main" class="ui-content">
    <form>
        <label for="switch">Simple Motor Control</label>
        <input type="checkbox" data-role="flipswitch" name="switch" id="ckLED">
    </form>
    <form>
        <label for="switch">Throughput</label>
        <input type="textbox" id="throughput">
    </form>
        <form>
        <label for="switch">Left Speed</label>
        <input type="textbox" id="leftspeed" value=0>
    </form>
    <form>
        <label for="switch">Right Speed</label>
        <input type="textbox" id="rightspeed" value=0>
    </form>
    <button id="wbutton">W</button>
 </div>
</div>
</body>
</html>
'''

@route('/action', method='POST')
def action():
    val = request.forms.get('strState')
    val2 = request.forms.get('strState2')
    keyCode = request.forms.get('keyPressed')
    #on = bool(int(val))
    #print bool(int(val2))
    #print on
    #print keyCode

 	
	#ser.write('r(0-9),')
    #ser.write('l(0-9)')
 

run(host='localhost', port=8000)
