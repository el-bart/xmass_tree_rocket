include <detail/config.scad>
h = 100;

module fin()
{
  translate([d/2, wall/2, 0])
    rotate([90, 0, 0])
      linear_extrude(wall)
        polygon(points=[
          [15, 40-15],
          [0, 40],
          [0, 0],
          [15, 15]
        ]);
}


module fins(n)
{
  for(i=[0:n-1])
    rotate([0, 0, i*360/n])
      fin();
}


module bottom()
{
  $fn=100;
  led_w = 10+0.5;
  a = sqrt( led_w*led_w / 2 );
  difference()
  {
    union()
    {
      fins(4);
      cylinder(d=d+2*wall, h=h); // main block
      cylinder(d1=d+a+2*wall, d2=d+2*wall, h=a); // nozzle cut
    }
    cylinder(d=d, h=h-2*wall);      // main block
    translate([0, 0, h])
      cube([12, 5, 5*wall], center=true); // LED-pass + cable hole
    cylinder(d1=d+a, d2=d, h=a);    // nozzle cut
  }
}

rotate([180, 0, 0])
  bottom();
