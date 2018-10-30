#include <argp.h>

/*
   Description of non-option arguments
*/
static char args_doc[] = "";

/*
  Program documentation.
*/
static char doc[] = "MINIX3 Firewall command line tool";

/*
   the argp structure--for use in main.
*/

extern struct argp_option options[];

error_t parse_opt (int key, char *arg, struct argp_state *state);

static struct argp argp = {options, parse_opt, args_doc, doc};

struct arguments
{                   
    int in;            /* --in - action to add rule */
    char *proto;        /* --proto - the  protocol of the packet (ALL, TCP, UDP. ICMP)*/
    char *srcip;           /* --srcip - the source IP of the packet */
    char *destip;        /* --destip - the destination IP of the packet */
    char *srcnetmask;     /* --srcnetmask - the source netmask of the packet (eg. 255.255.255.0) */
    char *port;             /* --destport - the destination port of the packet */
    char *action;         /* --action - the action to take on packets that match above criteria (BLOCK or UNBLOCK) */
    int print;           /* --print - print all the rules */
    char *del;            /* --delete - the rule to delete */ 
};