/* Common header files ********************************************************/
#include "oscil~common.h"

/* Function prototypes ********************************************************/
void *oscil_new(t_symbol *s, short argc, t_atom *argv);

/* The 'initialization' routine ***********************************************/
void oscil_tilde_setup(void)
{
	/* Initialize the class */
	oscil_class = class_new(gensym("oscil~"),
							(t_newmethod)oscil_new,
							(t_method)oscil_free,
							sizeof(t_oscil), 0, A_GIMME, 0);
	
	/* Specify signal input, with automatic float to signal conversion */
	CLASS_MAINSIGNALIN(oscil_class, t_oscil, x_f);
	
	/* Bind the DSP method, which is called when the DACs are turned on */
	class_addmethod(oscil_class, (t_method)oscil_dsp, gensym("dsp"), 0);
	
	/* Print message to Max window */
	post("oscil~ • External was loaded");
}

/* The 'new instance' routine *************************************************/
void *oscil_new(t_symbol *s, short argc, t_atom *argv)
{
	/* Instantiate a new object */
	t_oscil *x = (t_oscil *)pd_new(oscil_class);
    
	return common_new(x, argc, argv);
}

/******************************************************************************/
