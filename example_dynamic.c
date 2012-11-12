
#include <stdio.h>
#include "termcolor.h"

int main() {
    
    autoResetStyle(FALSE);
	cprint("${bd}This is a bold text${/bd} and ${ul}this is underlined text${/ul}\n\n");
    
    cprint("and ${bd}${ul}this is both bold and underlined text${/ul}${/bd} :) \n\n");
	cprint("background ${rb}red${bb}black${gb}green${yb}yellow${ub}blue${mb}magenta${cb}cyan${wb}white${/bg} and no background :) \n\n");
    
    cprint("${fg}foreground ${rf}red${bf}black${gf}green${yf}yellow${uf}blue${mf}magenta${cf}cyan${wf}white${/bf} and no foreground :) \n\n");
    cprint("${bl}${bg}background ${rb}red${bb}black${gb}green${yb}yellow${ub}blue${mb}magenta${cb}cyan${wb}white${/bg} and no background :) ${/bl} \n\n");
    cprint("${bl}${fg}foreground ${rf}red${bf}black${gf}green${yf}yellow${uf}blue${mf}magenta${cf}cyan${wf}white${/bf} and no foreground :)${/bl} \n\n");
    cprint("${rv} REVERSED COLORS ${/rv} ;) \n");
    
    cprint("${bi}${rb} High Intensity for red background ${/bg}${/bi}\n");
    cprint("${fi}${rf} High Intensity for red foreground ${/fg}${/fi}\n");
    
    resetStyle();
    return 0;
}
