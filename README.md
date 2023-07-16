# SetEnv-Current
C Routines to set the current environment in Scripts

I needed to be able to set the current local Environment variables from a program I developed called Panel from old mainframe days.

Panel (or nowadays Form) was developed over 40 years ago on an IBM 360 and carefully transferred from IBM Assembler to PL/I, then Pascal and now C.  More details soon....

However, I needed a way to set the environment variables.  The late Bob Stout had some routines that used to stuff keys into the MS/DOS keyboard buffer, so I developed some routines to do that for Windows. However, I soon learned that didn't work very well in BAT files.  Timing was the problem.

And so I modified the routines to write out SET instructions, and then CALL the newly created file to actually set the variables, and carry on with the BAT file.
