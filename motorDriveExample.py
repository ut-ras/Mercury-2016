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
  
    $(window).keydown(function(event){
    var keyCode = event.keyCode;
    alert(event.keyCode);
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
 </div>
</div>
</body>
</html>
'''

@route('/action', method='POST')
def action():
    val = request.forms.get('strState')
    keyCode = request.forms.get('keyPressed')
    on = bool(int(val))
    print on
    print keyCode

 	
	ser.write('r(0-9),')
    ser.write('l(0-9)')
 

run(host='localhost', port=8000)
