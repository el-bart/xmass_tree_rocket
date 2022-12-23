include <detail/config.scad>
h = 40;
d_int = 40;
d_ext = d_int + 2*wall;
spacing = 0.4;

module ogive_side(d_ext, h)
{
  $fn = 200;
  r = d_ext/2;
  p = (r*r + h*h) / (2*r);
  intersection()
  {
    translate([-p+r, 0])
      circle(r=p);
    square([p, p]);
  }
}


module ogive_shell(d_ext, h, wall)
{
  difference()
  {
    ogive_side(d_ext, h);
    ogive_side(d_ext-2*wall, h-wall);
  }
}


module ogive(d_ext, h, wall)
{
  rotate_extrude(angle=360, $fn=100)
    ogive_shell(d_ext, h, wall);
}


module top_core()
{
  $fn = 100;
  // bottom ring, for mounting
  difference()
  {
    cylinder(d=d_ext, h=h_edge);
    translate([0,0,-eps])
      cylinder(d1=d_int+2*spacing, d2=d_int, h=h_edge+2*eps);
  }
  translate([0, 0, h_edge])
    ogive(d_ext, h, wall);
}


module top()
{
  difference()
  {
    top_core();
    cylinder(d=6.2, h=2*h, $fn=80);
  }
}


top();
