#ifdef TIXML_USE_STL
#include <iostream>
#include <sstream>

using namespace std;
#else
#include <stdio.h>
#endif

#if defined( WIN32 ) && defined (TUNE)
#include <crtdbg.h>
_CrtMemState startMemState;
_CrtMemState endMemState;
#endif

#include "tinyxml.h" 		// 重要。
#include "tinystr.h"

bool XmlTest (const char * testString, const char* expected, const char* found, bool noEcho = false);
bool XmlTest (const char * testString, int expected, int found, bool noEcho = false );

static int gPass = 0;
static int gFail = 0;

bool XmlTest (const char* testString, const char* expected, const char* found, bool noEcho)
{
  bool pass = !strcmp( expected, found);
  if (pass )
    printf ("[pass]");
  else
    printf ("[fail]");
  if (noEcho)
    printf ("%s\n", testString);
  else
    printf ("%s [%s][%s]\n", testString, expected, found);
  if (pass )
    ++gPass;
  else
    ++gFail;
  return pass;
}

void NullLineEndings( char *p )
{
  while(p && *p ) {
    if ( *p == '\n' || *p == '\r' ) {
      *p = 0;
      return;
    }
    ++p;
  }
}

int main()
{
  const char* demoStart =
    "<?xml version=\"1.0\" standalone='no' >\n"
    "<!-- Our to do list data -->"
    "<ToDo>\n"
    "<!-- Do I need a secure PDA? -->\n"
    "<Item priority=\"1\" distance='近'> Go to the <bold> Toy Store!</bold></Item>"
    "<Item priority=\"2\" distance='无'> Do bills </Item>"
    "<Item priority=\"2\" distance='远 &amp; 回'> Look for Evil Dinosaurs! </Item>"
    "</ToDo>";
  {
    //The example parses from the character string (above):
#if defined ( WIN32 ) && defined (TUNE)
    _CrtMemCheckpoint( &startMemState );
#endif

    {
      //Write to a file and read it back, to check file I/O.

      TiXmlDocument doc( "demotest.xml" );
      doc.Parse( demoStart );

      if (doc.Error() )
	{
	  printf( "Error in %s: %s\n", doc.Value(), doc.ErrorDesc() );
	  exit(1);
	}
      doc.SaveFile();
    }

    TiXmlDocument doc( "demotest.xml" );
    bool loadOkay = doc.LoadFile();

    if ( !loadOkay )
      {
    	printf( "Could not load test file 'demotest.xml'. Error='%s'. Exiting.\n", doc.ErrorDesc() );
    	exit( 1 );
      }

    printf( " ** Demo doc read from disk: ** \n\n" );
    printf( " ** Printing via doc.Print **\n");
    doc.Print( stdout );

    // {
    //   printf( "** Printing via TiXmlPrinter **\n" );
    //   TiXmlPrinter printer;
    //   doc.Accept( &printer );
    //   fprintf( stdout, "%s", printer.CStr() );
    // }

    // #ifdef TIXML_USE_STL
    // {
    //   printf( "** Printing via operator<< **\n" );
    //   std::cout << doc;
    // }
    // #endif
    
    TiXmlNode* node = 0;
    TiXmlElement* todoElement = 0;
    TiXmlElement* itemElement = 0;

    //获取元素属性，删除一个元素。

    node = doc.FirstChild( "ToDo" );
    assert( node );
    todoElement = node->ToElement();
    assert( todoElement );

    node = todoElement->FirstChildElement();
    assert( node );
    itemElement = node->ToElement();
    assert( itemElement );
    itemElement->SetAttribute( "priority", 2);

    itemElement = itemElement->NextSiblingElement();
    assert( itemElement );
    itemElement->SetAttribute( "distance", "杏花村" );

    // // Remove the "Look for Evil Dinosaurs!" item.
    // // It si 1 more sibling away. We ask the parent to remove
    // // a particular child.

    itemElement = itemElement->NextSiblingElement();
    todoElement->RemoveChild( itemElement );

   // itemElement = 0;

    TiXmlElement item( "Item" );
    item.SetAttribute( "priority", "9" );
    item.SetAttribute( "distance", "非常远" );

    TiXmlText text( "Talk to:" );

    TiXmlElement meeting1( "Meeting" );
    meeting1.SetAttribute( "where", "School" );

    TiXmlElement meeting2( "Meeting" );
    meeting2.SetAttribute( "where", "Lunch" );

    TiXmlElement attendee1( "Attendee" );
    attendee1.SetAttribute( "name", "Marple" );
    attendee1.SetAttribute( "position", "teacher" );

    TiXmlElement attendee2( "Attendee" );
    attendee2.SetAttribute( "name", "Voel" );
    attendee2.SetAttribute( "position", "counselor" );

    // Assemble the nodes we've created:
    meeting1.InsertEndChild( attendee1 );
    meeting1.InsertEndChild( attendee2 );

    item.InsertEndChild( text );
    item.InsertEndChild( meeting1 );
    item.InsertEndChild( meeting2 );

    // And add the node to the existing list after the first child.
    node = todoElement->FirstChild( "Item" );
    assert( node );
    itemElement = node->ToElement();
    assert( itemElement );

    todoElement->InsertAfterChild( itemElement, item );

    printf( "\n** Demo doc processed: **\n\n" );

    doc.Print( stdout );

  }}
