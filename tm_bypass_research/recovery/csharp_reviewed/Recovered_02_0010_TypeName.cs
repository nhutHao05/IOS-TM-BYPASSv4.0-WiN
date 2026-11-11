using System;
using System.ComponentModel;
using System.Drawing;
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using Siticone.UI.WinForms;

public class Recovered_02_0010_TypeName : Form
{
	private IContainer Recovered_04_0033_Name = null;

	private RichTextBox Recovered_04_0034_Name;

	private RichTextBox Recovered_04_0035_Name;

	private SiticoneGradientButton Recovered_04_0036_Name;

	public Recovered_02_0010_TypeName()
	{
		Recovered_06_004e_Name();
	}

	private void Recovered_06_004a_Name(object P_0, EventArgs P_1)
	{
		Close();
	}

	private void Recovered_06_004b_Name(object P_0, EventArgs P_1)
	{
	}

	private void Recovered_06_004c_Name(object P_0, EventArgs P_1)
	{
		Close();
	}

	protected virtual void Recovered_06_004d_Name(bool P_0)
	{
		if (P_0 && Recovered_04_0033_Name != null)
		{
			Recovered_04_0033_Name.Dispose();
		}
		Dispose(P_0);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_004e_Name()
	{
		ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(Recovered_02_0010_TypeName));
		Recovered_04_0034_Name = new RichTextBox();
		Recovered_04_0035_Name = new RichTextBox();
		Recovered_04_0036_Name = new SiticoneGradientButton();
		SuspendLayout();
		Recovered_04_0034_Name.BackColor = Color.Black;
		Recovered_04_0034_Name.BorderStyle = BorderStyle.None;
		Recovered_04_0034_Name.Font = new Font("Segoe UI Semibold", 11f, FontStyle.Bold, GraphicsUnit.Point, 0);
		Recovered_04_0034_Name.ForeColor = Color.White;
		Recovered_04_0034_Name.Location = new Point(1, 1);
		Recovered_04_0034_Name.Name = "richTextBox1";
		Recovered_04_0034_Name.ReadOnly = true;
		Recovered_04_0034_Name.Size = new Size(229, 70);
		Recovered_04_0034_Name.TabIndex = 17;
		Recovered_04_0034_Name.Text = "";
		Recovered_04_0035_Name.BackColor = Color.Black;
		Recovered_04_0035_Name.BorderStyle = BorderStyle.None;
		Recovered_04_0035_Name.Font = new Font("Segoe UI Semibold", 11f, FontStyle.Bold, GraphicsUnit.Point, 0);
		Recovered_04_0035_Name.ForeColor = Color.White;
		Recovered_04_0035_Name.Location = new Point(12, 12);
		Recovered_04_0035_Name.Name = "richTextBox2";
		Recovered_04_0035_Name.ReadOnly = true;
		Recovered_04_0035_Name.Size = new Size(210, 25);
		Recovered_04_0035_Name.TabIndex = 18;
		Recovered_04_0035_Name.Text = "iDevice Activated Successfully";
		Recovered_04_0036_Name.BorderColor = Color.Lime;
		Recovered_04_0036_Name.BorderThickness = 1;
		Recovered_04_0036_Name.CheckedState.Parent = Recovered_04_0036_Name;
		Recovered_04_0036_Name.CustomImages.Parent = Recovered_04_0036_Name;
		Recovered_04_0036_Name.FillColor = Color.Red;
		Recovered_04_0036_Name.FillColor2 = Color.Red;
		Recovered_04_0036_Name.Font = new Font("Segoe UI", 9f);
		Recovered_04_0036_Name.ForeColor = Color.White;
		Recovered_04_0036_Name.HoveredState.Parent = Recovered_04_0036_Name;
		Recovered_04_0036_Name.Location = new Point(82, 39);
		Recovered_04_0036_Name.Margin = new Padding(2);
		Recovered_04_0036_Name.Name = "siticoneGradientButton1";
		Recovered_04_0036_Name.ShadowDecoration.Parent = Recovered_04_0036_Name;
		Recovered_04_0036_Name.Size = new Size(65, 20);
		Recovered_04_0036_Name.TabIndex = 19;
		Recovered_04_0036_Name.Text = "CLOSE";
		Recovered_04_0036_Name.Click += Recovered_06_004c_Name;
		base.AutoScaleDimensions = new SizeF(6f, 13f);
		base.AutoScaleMode = AutoScaleMode.Font;
		BackColor = Color.Lime;
		base.ClientSize = new Size(231, 72);
		base.ControlBox = false;
		base.Controls.Add(Recovered_04_0036_Name);
		base.Controls.Add(Recovered_04_0035_Name);
		base.Controls.Add(Recovered_04_0034_Name);
		ForeColor = SystemColors.ControlText;
		base.FormBorderStyle = FormBorderStyle.None;
		base.Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
		base.MaximizeBox = false;
		base.MinimizeBox = false;
		base.Name = "SuccessBoxActive";
		base.ShowIcon = false;
		base.StartPosition = FormStartPosition.CenterScreen;
		Text = "Success";
		base.Load += Recovered_06_004b_Name;
		ResumeLayout(performLayout: false);
	}
}
