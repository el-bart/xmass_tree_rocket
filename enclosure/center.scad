include <detail/config.scad>
h = 60;
d_int = 40;
d_ext = d_int + 2*wall;


module center()
{
  $fn = 100;
  d_start = 30+2*wall;
  cut = (d_ext - d_start)/2 + wall;
  difference()
  {
    union()
    {
      cylinder(d1=d_start, d2=d_ext, h=cut);
      translate([0, 0, cut])
        cylinder(d=d_ext, h=h); // main block
    }
    cube([12, 5, 2*cut+eps], center=true); // LED-pass + cable hole
    translate([0, 0, cut])
      cylinder(d=d_int, h=h+eps);   // main block
  }
  // edge for keepign top-dome
  translate([0, 0, cut+h-h_edge])
    difference()
    {
      cylinder(d=d_int, h=2*h_edge);
      translate([0, 0, -eps])
        cylinder(d=d_int-2*wall, h=2*h_edge+2*eps);
    }
}

center();
