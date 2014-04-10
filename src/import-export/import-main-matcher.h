/********************************************************************\
 * This program is free software; you can redistribute it and/or    *
 * modify it under the terms of the GNU General Public License as   *
 * published by the Free Software Foundation; either version 2 of   *
 * the License, or (at your option) any later version.              *
 *                                                                  *
 * This program is distributed in the hope that it will be useful,  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of   *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    *
 * GNU General Public License for more details.                     *
 *                                                                  *
 * You should have received a copy of the GNU General Public License*
 * along with this program; if not, contact:                        *
 *                                                                  *
 * Free Software Foundation           Voice:  +1-617-542-5942       *
 * 59 Temple Place - Suite 330        Fax:    +1-617-542-2652       *
 * Boston, MA  02111-1307,  USA       gnu@gnu.org                   *
\********************************************************************/
/** @addtogroup Import_Export
    @{ */
/**@file import-main-matcher.h
   @brief Transaction matcher main window
   @author Copyright (C) 2002 Benoit Gr�goire
   @author Christian Stimming    
*/

#ifndef GNC_IMPORT_MAIN_MATCHER_H
#define GNC_IMPORT_MAIN_MATCHER_H

#include <gnome.h>
#include "Transaction.h"

typedef struct _main_matcher_info GNCImportMainMatcher;

/** Create a new generic transaction dialog window and return it. 
    @param parent The parent GtkWidget. May be NULL.
    @param heading The heading label in the Importer window. May be NULL.
    @param all_from_same_account Set this to TRUE if ALL the transaction 
    that will be added with gnc_gen_trans_list_add_trans are from the same
    source account.  This will cause the account column to be hidden.
*/
GNCImportMainMatcher *gnc_gen_trans_list_new (GtkWidget *parent, 
					   const gchar* heading,
					   gboolean all_from_same_account);

/** Deletes the given object. */
void gnc_gen_trans_list_delete (GNCImportMainMatcher *info);

/** Add a newly imported Transaction to the Transaction Importer.
    @param gui The Transaction Importer to use.
    @param trans The Transaction to add.     The must contain at least
    one split, and this split must have been associated with an account
    Only the first split will be used for matching.  The 
    transaction must NOT be commited.
 */
void gnc_gen_trans_list_add_trans(GNCImportMainMatcher *gui, Transaction *trans);

/** Run this dialog and return only after the user pressed Ok, Cancel,
  or closed the window. This means that all actual importing will
  have been finished upon returning.
 */
gboolean gnc_gen_trans_list_run (GNCImportMainMatcher *info);

#endif
/**@}*/