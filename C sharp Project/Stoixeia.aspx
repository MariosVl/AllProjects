<%@ Page Title="Στοιχεία Επικοινωνίας" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeFile="Stoixeia.aspx.cs" Inherits="Default2" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" Runat="Server">
     <h2><%: Title %></h2>
    <p>
     <table class="nav-justified">
         <tr>
             <td>
                 <h4>Oνοματεπώνυμο</h4>
             </td>
             <td>
                 <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                 <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="TextBox1" ErrorMessage="Πρέπει να συμπληρώσετε το όνομα σας" ForeColor="Red">*</asp:RequiredFieldValidator>
             </td>
         </tr>
         <tr>
             <td>&nbsp;</td>
             <td>&nbsp;</td>
         </tr>
         <tr>
             <td>
                 <h4>Περιφέρεια</h4>
             </td>
             <td id="StateList">
                 <asp:DropDownList ID="DropDownList1" runat="server">
                     <asp:ListItem>Επιλέξτε Περιφέρεια</asp:ListItem>
                     <asp:ListItem>Κεντρικής Μακεδονίας</asp:ListItem>
                     <asp:ListItem>Θεσσαλίας</asp:ListItem>
                 </asp:DropDownList>
                 <asp:CompareValidator ID="CompareValidator1" runat="server" ControlToValidate="DropDownList1" ErrorMessage="Πρέπει να επιλέξετε περιφέρεια" ForeColor="Red" Operator="NotEqual" ValueToCompare="Επιλέξτε Νομό">*</asp:CompareValidator>
             </td>
         </tr>
         <tr>
             <td>&nbsp;</td>
             <td>&nbsp;</td>
         </tr>
         <tr>
             <td>
                 <h4>Ηλικία</h4>
             </td>
             <td>
                 <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
                 <asp:RangeValidator ID="RangeValidator1" runat="server" ControlToValidate="TextBox3" ErrorMessage="Δώστε ηλικία στα όρια" ForeColor="Red" MaximumValue="67" MinimumValue="18">*</asp:RangeValidator>
                 <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" ControlToValidate="TextBox3" ErrorMessage="Δώστε ηλικία" ForeColor="Red">*</asp:RequiredFieldValidator>
             </td>
         </tr>
         <tr>
             <td>&nbsp;</td>
             <td>&nbsp;</td>
         </tr>
         <tr>
             <td>
                 <h4>Εmail</h4>
             </td>
             <td>
                 <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                 <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" ControlToValidate="TextBox2" ErrorMessage="Το email δεν είναι σωστο" ForeColor="Red" ValidationExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*">*</asp:RegularExpressionValidator>
                 <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ControlToValidate="TextBox2" ErrorMessage="Συμπλήρωσε e mail" ForeColor="Red">*</asp:RequiredFieldValidator>
             </td>
         </tr>
         <tr>
             <td>&nbsp;</td>
             <td>&nbsp;</td>
         </tr>
         <tr>
             <td>&nbsp;</td>
             <td>&nbsp;</td>
         </tr>
         <tr>
             <td>&nbsp;</td>
             <td>
                 <asp:Button ID="Button1" runat="server" Text="Υποβολη" OnClick="Button1_Click" />
             </td>
         </tr>
     </table>
        </p>
    <p>

    </p>
     <asp:ValidationSummary ID="ValidationSummary1" runat="server" ForeColor="Red" HeaderText="Προσοχή" />
</asp:Content>

